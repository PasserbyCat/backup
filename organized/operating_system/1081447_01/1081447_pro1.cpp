
/*
    source: https://www.ibm.com/developerworks/aix/library/au-spunix_sharedmemory/
    compile: gcc -o shm shm.c -lrt
    exec: ./shm
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/file.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <iostream>
#include <string>

using std::endl;
using std::cin;
using std::cout;
using std::string;

void error_and_die(const char *msg) {
  perror(msg);
  exit(EXIT_FAILURE);
}

int main(int argc, char *argv[]) {
  int r;
  
  const char *memname = "sample";
  const size_t region_size = sysconf(_SC_PAGE_SIZE);
  
  int fd = shm_open(memname, O_CREAT | O_TRUNC | O_RDWR, 0666);
  if (fd == -1)
    error_and_die("shm_open");
    
  r = ftruncate(fd, region_size);
  if (r != 0)
    error_and_die("ftrincate");
    
  int *ptr = (int *)mmap(0, region_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
  if (ptr == MAP_FAILED)
    error_and_die("mmap");
  close(fd);

  //ptr[0] => x
  //ptr[1] => y
  ptr[2] = 0;//right = 1, left = -1
  ptr[3] = 0;//dowm = 1, up = -1
  ptr[4] = 0;

  string input = argv[1];
  int seed = 0;
  for (int i = 0; i < input.size(); i++) {
    seed *= 10;
    seed += input[i] - '0';
  }
  
  pid_t pid = fork();
  /*FIRST 2 LINE*/
  if (pid < 0) {
    fprintf(stderr, "Fork Failed");
    exit(-1);
  }
  else if (pid == 0) { //child
    srand(seed + 1);
    int a = rand() % 10, b = rand() % 10, i = 0;
    
    while (i < 5) {
      if (ptr[4] == 1) {
        cout << "[" << getpid() << " Child]; OK" << endl;
        ptr[4] = 2;
      }
      if (ptr[4] == 3) {
        cout << "[" << getpid() << " Child]: Miss, ";
        if (ptr[0] == a && ptr[1] == b) {//parent win
          cout << "you win" << endl;
          ptr[0] = a;
          ptr[1] = b;
          break;
        }
        else {
	  if (i == 4) {
	    cout << "you lose" << endl;
	    ptr[0] = a;
	    ptr[1] = b;
	    break;
	  }
          if (ptr[1] < b) {
            cout << "down ";
	    ptr[3] = 1;
          }
          else if (ptr[1] > b) {
	    cout << "up ";
	    ptr[3] = -1;
          }
          if (ptr[0] < a) {
            cout << "right";
	    ptr[2] = 1;
	  }
          else if (ptr[0] > a) {
	    cout << "left";
	    ptr[2] = -1;
	  }
	  cout << endl;
	  ptr[4] = 2;
	  i++;
	}
      }
    }
    ptr[4] = 4;
    
    exit(0);
  }
  else { //parent
    srand(seed);
    int x = 10, y = 10, xu = 0, xd = 9, yu = 0, yd = 9, i = 0;
    while (i < 6) {
      if (ptr[4] == 0) {
        cout << "[" << getpid() << " Parent]: Create a child " << pid << endl;
        ptr[4] = 1;
      }
      if (ptr[4] == 2) {
        if (ptr[2] == 1) {
          xu = x + 1;
	  ptr[2] = 0;
        }
        else if (ptr[2] == -1) {
	  xd = x - 1;
	  ptr[2] = 0;
        }
        else if (x != 10) {
          xd = x;
          xu = x;
        }
        if (ptr[3] == 1) {
	  yu = y + 1;
	  ptr[3] = 0;
        }
        else if (ptr[3] == -1) {
  	  yd = y - 1;
	  ptr[3] = 0;
        }
        else if (y != 10) {
          yu = y;
          yd = y;
        }
        i++;
        x = rand() % (xd - xu + 1) + xu;
        y = rand() % (yd - yu + 1) + yu;
        cout << "[" << getpid() << " Parent]: Guess [" << x << "," << y << "]" << endl;
        ptr[0] = x;
        ptr[1] = y;
        ptr[4] = 3;
      }
      if (ptr[4] == 4) {
        cout << "[" << getpid() << " Parent]: Target ["
             << ptr[0] << "," << ptr[1] << "]" << endl;
        break;
      }
    }
    
    int status;
    waitpid(pid, &status, 0);
  }
  
  r = munmap(ptr, region_size);
  if (r != 0)
    error_and_die("mummap");
    
  r = shm_unlink(memname);
  if (r != 0)
    error_and_die("shm_unlink");
  return 0;
}

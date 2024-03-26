var state = ["Alabama","Alaska","Arizona","Arkansas","California",
"Colorado","Connecticut","Delaware","Florida","Georgia",
"Hawaii","Idaho","Illinois","Indiana","Iowa",
"Kansas","Kentucky","Louisiana","Maine","Maryland",
"Massachusetts","Michigan","Minnesota","Mississippi","Missouri",
"Montana","Nebraska","Nevada","New Hampshire","New Jersey",
"New Mexico","New York","North Carolina","North Dakota","Ohio",
"Oklahoma","Oregon","Pennsylvania","Rhode Island","South Carolina",
"South Dakota","Tennessee","Texas","Utah","Vermont",
"Virginia","Washington","WestVirginia","Wisconsin","Wyoming"];//50州
var height=[2.291288,3.834058,3.929377,6.236986,6.637771,7.355270,8.027453,
8.537564,10.860018,11.456439,12.424975,12.614278,12.775367,13.044922,
13.297368,13.349157,13.896043,14.501034,15.407790,15.454449,15.630099,
15.890249,16.976749,18.264994,19.437592,19.904271,21.167192,22.366046,
22.766642,24.894377,25.093027,28.635118,29.250641,31.477135,31.620405,
32.718802,36.734861,36.847931,38.527912,41.487950,48.725148,53.593376,
57.271022,64.993615,68.762272,87.326342,102.861557,168.611417,293.622751];//49筆
var merge =[
[-15,-29],//01 
[-17,-26],//02 
[-14,-16],//03 
[-13,-32],//04 
[-35,-44],//05 
[-36,-46],//06 
[-7,-38],//07 
[-19,-41],//08 
[-49,1],//09 
[-21,-30],//10 
[-37,6],//11 
[-4,-42],//12 
[-48,8],//13 
[-34,-45],//14 
[-22,-28],//15 
[-27,2],//16 
[-3,-31],//17 
[-6,-43],//18 
[-12,3],//19 
[-1,-18],//20 
[-50,11],//21 
[-20,17],//22 
[-8,20],//23 
[5,7],//24 
[-23,9],//25 
[16,19],//26 
[-24,-40],//27 
[4,15],//28 
[-47,10],//29 
[-25,12],//30 
[-10,18],//31 
[-2,27],//32 
[21,29],//33 
[24,26],//34 
[-11,25],//35 
[-5,28],//36 
[30,31],//37 
[-39,33],//38 
[-9,-33],//39 
[13,14],//40 
[23,32],//41 
[22,36],//42 
[35,40],//43 
[41,42],//44 
[37,38],//45 
[34,43],//46 
[39,44],//47 
[45,46],//48 
[47,48]];//49 
function progress(){
	var dis = document.form.dis.value;
	var target = document.form.target.value;
	var output=""


    /*----------------- Your Code Start-------------*/
	var stateposition;
	
	for (var i = 0; i < 50; i++)
		if (state[i] == target)
			stateposition = i + 1;
	
	output = which(dis, stateposition, output);
	
	if(output != "")
    {
		var temp1 = output.split(",");
		temp1.sort();
		output = temp1;
	}

    /*----------------- Your Code End --------------*/
    document.getElementById('out').innerHTML= output;
}

function which(dis, stateposition, output)
{
	if(dis == 1 || dis == 0)
		return output;
	
	for(var j = 0;; j++) {
		if(merge[j][0] == (0 - stateposition) && merge[j][1] < 0) {
			output = state[0 - 1 - merge[j][1]];
			output = up(dis, j + 1, output, 1);
			return output;
		}
		else if(merge[j][1] == (0 - stateposition) && merge[j][0] < 0) {
			output = state[0 - 1 - merge[j][0]];
			output = up(dis, j + 1, output, 1);
			return output;
		}
		else if(merge[j][1] == (0 - stateposition) && merge[j][0] > 0) {
			output = down(dis, merge[j][0] - 1, output, 1);
			output = up(dis, j + 1, output, 1);
			return output;
		}
		else if(merge[j][0] == (0 - stateposition) && merge[j][1] > 0) {
			output = down(dis, merge[j][1] - 1, output, 1);
			output = up(dis, j + 1, output, 1);
			return output;
		}
		
		else if(j == 48)//49 - 1
			return output;
	}
}

function down(dis, j, output, limit)
{
	if(limit >= (dis - 1))
		return output;
	
	if(merge[j][0] > 0 && merge[j][1] > 0) {
		output = down(dis, merge[j][0] - 1, output, limit + 1);
		output = down(dis, merge[j][1] - 1, output, limit + 1);
		return output;
	}
	else if(merge[j][0] < 0 && merge[j][1] > 0) {
		if(output != "")
			output += ",";
		output += state[0 - 1 - merge[j][0]];
		return down(dis, merge[j][1] - 1, output, limit + 1);
	}
	else if(merge[j][0] > 0 && merge[j][1] < 0) {
		if(output != "")
			output += ",";
		output += state[0 - 1 - merge[j][1]];
		return down(dis, merge[j][0] - 1, output, limit + 1);
	}
	else if(merge[j][0] < 0 && merge[j][1] < 0) {
		if(output != "")
			output += ",";
		output += state[0 - 1 - merge[j][0]];
		output += ","+ state[0 - 1 - merge[j][1]];
		return output;
	}
}

function up(dis, j, output, limit)
{
	if(limit >= (dis - 1))
		return output;
	
	if(height[j - 1] >= 50)
		return output;
	
	for(var i = 0;; i++) {			
		if(merge[i][0] == j && merge[i][1] < 0) {
			output += ","+ state[0 - 1 - merge[i][1]];
			return up(dis, i + 1, output, limit + 1);
		}
		else if(merge[i][1] == j && merge[i][0] < 0) {
			output += ","+ state[0 - 1 - merge[i][0]];
			return up(dis, i + 1, output, limit + 1);
		}
		else if(merge[i][0] == j && merge[i][1] > 0) {
			if(height[i] >= 50)
				return output;
			output = up(dis, i + 1, output, limit + 1);
			output = down(dis, merge[i][1] - 1, output, limit + 1);
			return output;
		}
		else if(merge[i][1] == j && merge[i][0] > 0) {
			if(height[i] >= 50)
				return output;
			output = findup(dis, i + 1, output, limit + 1);
			output = finddown(dis, merge[i][0] - 1, output, limit + 1);
			return output;
		}
		
		if(i == 48)//49 - 1
			return output;
	}
}

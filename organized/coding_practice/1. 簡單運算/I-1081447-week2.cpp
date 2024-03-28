//Body Mass Index Calculator & TDEE Calculator
/*
BMR
m: weight(kg)
■ h:height(cm)
■ a: age(year)
■ s: gender, s=5(male), s=-161(female)
■ BMR=10*m+6.25*h-5*a+s

Category TDEE
Sedentary(office job) : BMR*1.2
Light Exercise(1-2 days/week) : BMR*1.375
Moderate Exercise(3-5 days/week) : BMR*1.55
Heavy Exercise(6-7 days/week) : BMR*1.725
Athlete(2x per day) : BMR*1.9
*/
#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
	double gender = 0, year = 0, kg = 0, activity = 0, bmr = 0, cm = 0, m = 0, bmi = 0;
	cout << "Gender(Male:1/Female:2): ";
	cin >> gender;
	cout << "Age(year): ";
	cin >> year;
	cout << "mass(kg): ";
	cin >> kg;
	cout << "height(cm): ";
	cin >> cm;
	cout << "Activity List\n1.Sedentary(office job)\n2.Light Exercise(1 - 2 days / week)\n3.Moderate Exercise(3 - 5 days / week)\n4.Heavy Exercise(6 - 7 days / week)\n5.Athlete(2x per day)";
	cout << "\nActivity: ";
	cin >> activity;
	if (gender == 1) 
		bmr = (kg * 10) + cm * 6.25 - (year * 5) + 5;
	else
		bmr = (kg * 10) + cm * 6.25 - (year * 5) - 161;
	m = cm / 100;
	bmi = kg / (m * m);
	if (gender == 1)
		cout << "Gender: Male" << endl;
	else
		cout << "Gender: Female" << endl;
	cout << "Age(year): " << year << endl;
	cout << "Mass(kg): " << kg << endl;
	cout << "Height(cm): " << cm << endl;
	cout << "BMI: " << setprecision(5) << bmi << endl;
	if (bmi < 18.5)
		cout << "You are Underweight" << endl;
	else if (bmi < 24)
		cout << "You are Normal" << endl;
	else if (bmi < 27)
		cout << "You are Overweight" << endl;
	else if (bmi < 30)
		cout << "You are Moderately obese" << endl;
	else if (bmi < 35)
		cout << "You are Severely obese" << endl;
	else
		cout << "You are Very severely obese" << endl;
	cout << "BMR: " << floor(bmr) << endl;
	if (activity == 1) {
		cout << "You are Sedentary" << endl;
		bmr = bmr * 1.2;
	}
	if (activity == 2){
		cout << "You are Light Exercise" << endl;
		bmr = bmr * 1.375;
	}
	if (activity == 3){
		cout << "You are Moderate Exercise" << endl;
		bmr = bmr * 1.55;
	}
	if (activity == 4){
		cout << "You are Heavy Exercise" << endl;
		bmr = bmr * 1.725;
	}
	if (activity == 5){
		cout << "You are Athlete" << endl;
		bmr = bmr * 1.9;
	}
	cout << "TDEE: " << bmr;
	system("pause");
	return 0;
}
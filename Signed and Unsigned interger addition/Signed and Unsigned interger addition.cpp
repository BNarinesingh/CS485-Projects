//CS485 Project 1 Signed Number Addition: Two's Complement 
//Copyright (c) 2015 Kevin Hill, Barindra Narinesingh. All rights reserved.

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string convertToBinary(int signN) {
	string binaryN;

	if (signN < 0) {
		signN = abs(signN);
	}


	do {
		if ((signN) % 2 == 0)
			binaryN += '0';
		else
			binaryN += '1';

		signN = signN / 2;

	} while (signN != 0);


	do {
		if (binaryN.size() != 8)
			binaryN += '0';
	} while (binaryN.size() != 8);


	reverse(binaryN.begin(), binaryN.end());

	return binaryN;

}

string convertToneComplement(int signN) {
	string oneComplementN;

	if (signN < 0) {
		signN = abs(signN);
	}

	do {
		if ((signN) % 2 == 0)
			oneComplementN += '1';
		else
			oneComplementN += '0';
		signN = signN / 2;
	} while (signN != 0);

	do {
		if (oneComplementN.size() != 8)
			oneComplementN += '1';
	} while (oneComplementN.size() != 8);

	reverse(oneComplementN.begin(), oneComplementN.end());
	return oneComplementN;

}


string convertTotwoComplement(string oneComplementS) {

	string twoComplementN, carryN, overflowN;
	int y = 7, carryflag = 1;

	carryN += '1';


	do {
		if (carryflag == 1) {
			if (oneComplementS.at(y) == '0') {
				twoComplementN += carryN;
				carryflag = 0;
			}
			else
				twoComplementN += '0';
		}
		else
			twoComplementN += oneComplementS[y];

		y--;

	} while (y != -1);

	reverse(twoComplementN.begin(), twoComplementN.end());
	return twoComplementN;

}


string summationOftwoN(string twoComp1, string twoComp2) {

	string	carryN,
		overflowN,
		SumoftheTwo;

	int y = 7;
	int carryflag = 0, errorflag = 0;
	
	carryN += '1';

	// Adds the first 7 binary bits...........................................................
	do {
		if (twoComp1.at(y) == '0' && twoComp2.at(y) == '0') {
			if (carryflag == 0)
				SumoftheTwo += '0';
			else if (carryflag == 1) {
				SumoftheTwo += '1';
				carryflag = 0;
			}
		}
		else if (twoComp1.at(y) == '0' && twoComp2.at(y) == '1' || twoComp1.at(y) == '1' && twoComp2.at(y) == '0') {
			if (carryflag == 1) {
				SumoftheTwo += '0';
				carryflag = 1;
			}
			else if (carryflag == 0) {
				SumoftheTwo += '1';
			}
		}
		else if (twoComp1.at(y) == '1' && twoComp2.at(y) == '1') {
			if (carryflag == 1) {
				SumoftheTwo += '1';
				carryflag = 1;
			}
			else if (carryflag == 0) {
				SumoftheTwo += '0';
				carryflag = 1;
			}
		}
			y--;

	} while (y != 0);
	
	

	//adds the last binary bit...........................................................

	if (twoComp1.at(y) == '0' && twoComp2.at(y) == '0') {
		if (carryflag == 1) {
			SumoftheTwo += '1';
			errorflag = 1;
		}
		else
			SumoftheTwo += '0';
		}

	else if (twoComp1.at(y) == '0' && twoComp2.at(y) == '1' || twoComp1.at(y) == '1' && twoComp2.at(y) == '0') {
		if (carryflag == 1) {
			SumoftheTwo += '0';
		}
		else 
			SumoftheTwo += '1';
			
	}

	else if (twoComp1.at(y) == '1' && twoComp2.at(y) == '1') {
		if (carryflag == 1) {
			SumoftheTwo += '1';
		}
		else {
			errorflag = 1;
			SumoftheTwo += '0';
			}
	}


	reverse(SumoftheTwo.begin(), SumoftheTwo.end());
	
	if (errorflag != 1)
		return SumoftheTwo;

	else {
		string twoCompERROR;
		twoCompERROR = "......Overflow/Carry ERROR answer out of bounds for twos complement addition [-128,127].....";
		return twoCompERROR;
	}

}

void addNumbers(int num1, int num2, int sum3) {

	if (num1 < 0 && num2 > 0)
		cout << "(" << num1 << ") +" << num2 << " = " << sum3;
	else if (num1 > 0 && num2 < 0)
		cout << num1 << " + (" << num2 << ") = " << sum3;
	else if (num1 < 0 && num2 < 0)
		cout << "(" << num1 << ")" <<" + " << "(" << num2 << ") =" << sum3;
	else
		cout << num1 << " + " << num2 << " = " << sum3;
	
	cout << endl << endl;
}

//converts the string back to decimal

int convertTodecimal(string BinaryNumber) {
	int decimal; int multipleoftwo=1; int y = 6;


	if (BinaryNumber.at(7) == '1')
		decimal = 1;
	else
		decimal = 0;

	do {
		multipleoftwo= multipleoftwo*2;
		if (BinaryNumber.at(y) == '1') {
			decimal = decimal + multipleoftwo;
		}

			y--;

	} while (y != 1);

	if (BinaryNumber.at(y) == '1')
		decimal = decimal*-1;




	return decimal;
}



int main() {

	double signNumber1, signNumber2;
	string binaryNumber1, binaryNumber2;
	string oneComplement1, oneComplement2;
	string twoComplement1, twoComplement2;
	string summation;
	int choice = 0;

	cout << endl;

	cout << "Enter the first number: " << endl;
	cin >> signNumber1;

	cout << "Enter the second number: " << endl;
	cin >> signNumber2;

	if (signNumber1 <-128 || signNumber1 > 127) {
		cout << "Please enter a number that is within range!" << endl;
		return 0;
	}

	if (signNumber2 <-128 || signNumber2 > 127) {
		cout << "Please enter a number that is within range!" << endl;
		return 0;
	}
        
        if (signNumber1 ==0 || signNumber2 ==0){
            cout<<"0 cannot be an input!"<<endl;
            return 0;
        }
       

	
// Convert 1st number to binary..............................................................................
	
		binaryNumber1 = convertToBinary(signNumber1);

		cout << "The 1st Binary Number is: " << endl;
		cout << binaryNumber1;
		cout << endl;

		if (signNumber1 < 0) {

			// Convert 1st number to Ones complement ONLY CONVERTS IF NUMBER INPUT WAS NEGATIVE..............................................................................
			oneComplement1 = convertToneComplement(signNumber1);

			// Convert 1st number to twos complement..............................................................................
			twoComplement1 = convertTotwoComplement(oneComplement1);

		}
		else
			twoComplement1 = binaryNumber1;

		if (signNumber1 < 0) {
			cout << "The 1st Number One's Complement is: " << endl;
			cout << oneComplement1;
			cout << endl;


			cout << "The 1st Number Two's Complement is: " << endl;
			cout << twoComplement1;
			cout << endl;
		}
	

	//..............................................................................................................
	//..............................................................................................................
	// Convert 1st number to binary..............................................................................

		binaryNumber2 = convertToBinary(signNumber2);

		cout << "The 2nd Binary Number is: " << endl;
		cout << binaryNumber2;
		cout << endl;

		if (signNumber2 < 0) {

			// Convert 1st number to Ones complement ONLY CONVERTS IF NUMBER INPUT WAS NEGATIVE..............................................................................
			oneComplement2 = convertToneComplement(signNumber2);

			// Convert 1st number to twos complement..............................................................................
			twoComplement2 = convertTotwoComplement(oneComplement2);

		}
		else
			twoComplement2 = binaryNumber2;

		if (signNumber2 < 0) {
			cout << "The 2nd Number One's Complement is: " << endl;
			cout << oneComplement2;
			cout << endl;


			cout << "The 2nd Number Two's Complement is: " << endl;
			cout << twoComplement2;
			cout << endl;
		}
		



	//Summation of the two numbers via binary 

	summation = summationOftwoN(twoComplement1, twoComplement2);
	cout << "The Sum of the two Numbers are: " << endl;
	cout << summation;
	cout << endl<<endl<<endl;

	addNumbers(signNumber1, signNumber2, convertTodecimal(summation));


	cout << "End of Program " << endl;
	system("PAUSE");
	return 0;

}

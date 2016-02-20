/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/

bool isValid(char *dob)
{
	bool isValid = true;

	for (int i = 0; i < 10; i++)
	{
		if ((i == 2) || (i == 5))
		{
			if (dob[i] != '-')
			{
				isValid = false;
				break;
			}
		}
		else
		{
			int num = dob[i] - '0';

			if ((num < 0) || (num > 9))
			{
				isValid = false;
				break;
			}
		}
	}

	return isValid;
}

bool isLeapYear(int year)
{
	bool leapYearFlag = false;

	if (((year % 4 == 0) && !(year % 100 == 0)) || (year % 400 == 0))
		leapYearFlag = true;

	return leapYearFlag;
}


long timeStamp(char *dob)
{
	int year, month, date;
	bool leapYearFlag;
	long uniquedate = -1;

	if (!isValid(dob))
		return-1;

	year = 0;
	for (int i = 6; i <= 9; i++)
		year = year * 10 + dob[i] - '0';

	leapYearFlag = isLeapYear(year);

	month = (dob[3] - '0') * 10 + dob[4] - '0';
	date = (dob[0] - '0') * 10 + dob[1] - '0';

	if (month < 13)
	{
		if ((month == 1) || (month == 3) || (month == 5) || (month == 7) || (month == 8) || (month == 10) || (month == 12))
		{
			if (date <= 31)
				uniquedate = year * 10000 + month * 100 + date;
		}
		else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
		{
			if (date <= 30)
				uniquedate = year * 10000 + month * 100 + date;
		}
		else
		{
			if (isLeapYear(year) == 1)
			{
				if (date <= 29)
					uniquedate = year * 10000 + month * 100 + date;
			}
			else
			{
				if (date <= 28)
					uniquedate = year * 10000 + month * 100 + date;
			}
		}
	}

	return uniquedate;
}


int isOlder(char *dob1, char *dob2) {
	long d1, d2;
	int  result;

	
	d1 = timeStamp(dob1);
	d2 = timeStamp(dob2);

	if ((d1 == -1) || (d2 == -1))
		return -1;
	
	else if (d1 == d2)
		result = 0;

	else if (d1 < d2)
		result = 1;

	else
		result = 2;

	return result;
}

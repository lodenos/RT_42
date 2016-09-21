__kernel void hello(__global char* string)
{
	string[0] = 't';
	string[1] = 'a';
	string[2] = ' ';
	string[3] = 'm';
	string[4] = 'e';
	string[5] = 'r';
	string[6] = 'e';
	string[7] = 'g';
	string[8] = 'g';
	string[9] = 'g';
	string[10] = 'g';
	string[11] = 'd';
	string[12] = '!';
	string[13] = '\0';
}

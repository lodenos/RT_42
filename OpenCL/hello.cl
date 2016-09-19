__kernel void hello(__global char* string)
{
	string[0] = 'p';
	string[1] = 'd';
	string[2] = ' ';
	string[3] = 'o';
	string[4] = 'p';
	string[5] = 'e';
	string[6] = ' ';
	string[7] = 'g';
	string[8] = 'g';
	string[9] = 'g';
	string[10] = 'g';
	string[11] = 'd';
	string[12] = '!';
	string[13] = '\0';
}

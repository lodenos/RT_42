
unsigned int    limit(float x)
{
    if (x > 255)
        return 0xFF;
    else if (x < 0)
        return 0x00;
    return (unsigned int)x;
}

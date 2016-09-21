__kernel void   run_scene(__global char *test)
{
    int i;

    i = -1;
    while(test[++i])
        test[i] = 64;
}

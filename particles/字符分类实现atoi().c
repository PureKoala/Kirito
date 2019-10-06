double atoi(char * st)
{
    int i, len;
    double result = 0;
    len = strlen(st);

    for(i = 0;i < len; i++)
    {
        if(isdigit(st[i]))
        {
            result += ((st[i]-'0')*pow(10.(len-i-1)));
        }
        else
        {
            return 0;
        }
    }
    return result;
}
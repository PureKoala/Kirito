//两个之间不换行版本


while(feof(file1) == 0 || feof(file2) == 0)    
{        
    int len;        
    rintf("This is the %d circle\n",i);       
    char line_temp1[LEN];        
    char line_temp2[LEN];  //定义两个自动变量，在while循环一次后，自动释放，然后再重新分配内存        
    if((fgets(line_temp1, LEN, file1)) != NULL)        
    {            
        len = strlen(line_temp1);            
        line_temp1[len - 1] = '\0';            
        fputs(line_temp1, stdout);        
    }        
        if((fgets(line_temp2, LEN, file2)) != NULL)            
        fputs(line_temp2, stdout);        
        i++;    
}

//两个之间换行版本

while(feof(file1) == 0 || feof(file2) == 0)    
{        
    printf("This is the %d circle\n",i);        
    char line_temp1[LEN];        
    char line_temp2[LEN];  //定义两个自动变量，在while循环一次后，自动释放，然后再重新分配内存        
    if((fgets(line_temp1, LEN, file1)) != NULL)            
    fputs(line_temp1, stdout);        
    if((fgets(line_temp2, LEN, file2)) != NULL)            
    fputs(line_temp2, stdout);        
    i++;    
}

//主要看的是最开始while的判断条件

if(scanf("%d", &monthnum) == 1)    
{        
    for(i = 0; i < monthnum; i++)        
    {            
        total += months[i].days;            
        ThisMonth = months[i].days;        
        }    
}   //先判断是不是数字，如果是就读取，因为整型不能接受字符串，而字符串可以接受单个输入数字    
        
else if(scanf("%s", monthname) == 1)    
    {        
        for(i = 0; i < LEN; i++)        
        {            
            if(0 == i)                
                monthname[i] = toupper(monthname[i]);           
            else                
                 monthname[i] = tolower(monthname[i]);        
        }        
        for(i = 0; i < 12; i++)        
        {            
            total += months[i].days;  //进来先加一遍，月份是不是对另说            
            if(strcmp(monthname, months[i].name) == 0)            
            {                
                whether = true;                
                    
                ThisMonth = months[i].days;                
                i = i + 1;                
                break;            
            }        
    }

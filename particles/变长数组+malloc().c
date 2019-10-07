int n = 5;
int m = 6;
int ar2[n][m];//n x m的变长数组(VLA)
int (* p2)[6];
int (* p3)[m];
p2 = (int (*)[6]) malloc(n * 6 * sizeof(int));//n x 6的数组
p3 = (int (*)[m]) malloc(n * m * sizeof(int));//n x m的数组
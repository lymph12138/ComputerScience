数组：
    声明：
        int states[50];
        float candy[365];
        char code[20];
    初始化：
        int powers[6] =｛1, 2, 3, 4, 5, 6}; 
        int days[] = {31, 30, 28};//sizeof days/sizeof days[0]=3;
        int days[6] = {31, [1]=28, 31, [4]=30, [2]=44};//{31, 28, 44, 0, 30, 0}
    多维数组：
        int rain[5][12];
        int rain[2][3] = {{1, 2}, {3, 4}};//rain[0][2]=0  rain[1][0]=3  rain[1][1]=4
        int rain[2][3] = {1,2,3,4};//rain[0][2]=3  rain[1][0]=4  rain[1][1]=0
指针：
    声明：
        short dates[4];
        short * pti;
        double bills[4];
        double * ptr;
    初始化：
        pti = dates;
        ptr = bills;
    性质：
        pti + 1 == &dates[1];
        *(ptr + 2) == bills[2];
        指针加1，指针的值递增它所指向的类型的大小
        * 优先级大于 +
        
p83(3~5)
3.假定以I和O分别表示入栈和出栈。写出判定操作序列是否合法。
A.IOIIOIOO  B.IOOIOIIO  C.IIIOIOIO  D.IIIOOIOO
bool judge(char A[])
{
    int numberO=0;
    int numberI=0;
    int i=0;
    while(A[i]!='\0')
    {
        if(A[i]=='I')
            numberI++;
        else
            numberO++;
        if(numberI<numberO)
            return false;
        i++;
    }
    if(numberI!=numberO)
        return false;
    return true;
}
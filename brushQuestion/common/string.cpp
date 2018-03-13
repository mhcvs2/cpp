

inline void MyStrCpy(char *src, char *dst)
{
	int i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
}
//--------------------------------------------------------------
inline int MyStrCmp(char *src, char *dst)
{
	int i = 0;
	while (src[i] && dst[i])
	{
		if (src[i] != dst[i])
			return 0;
		i++;
	}
	if (src[i] == 0 && dst[i] == 0)
		return 1;
	return 0;
}
//--------------------------------------------------------------
inline int MyStrLen(char *str)
{
    int j = 0;
    while(str[j] != '\0') 
    {
        j++;
    }
    return j;
}
//-------------------------------------------------
inline int GetCharInt(char ch)
{
    return ch;
}
//------------------------------------------------
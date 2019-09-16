#include <stdio.h>
#include <fcntl.h>
#include <io.h>


int main()
{
    _setmode(_fileno(stdout), 0x00020000);

    int i,n;

    scanf("%d",&n);

    for(i=1;i<=n;i++)
    {
       wprintf(L"\x25a0");
    }

    return 0;
}

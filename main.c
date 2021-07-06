/* Author : Sarun Kumar
            mvsarun6
*/

/* pre req:
D2XX driver : https://ftdichip.com/drivers/d2xx-drivers/
              install "setup executable"
			  Also get lib package

FT_PROG : https://ftdichip.com/utilities/#FT_PROG
*/

// build command : gcc ftd2xx.dll main.c -o mypro

//device : FT232RL


#define FTD2XX_STATIC

#include "ftd2xx.h"
#include "stdio.h"

#define CHECKSTATUS(sts) if(sts!=FT_OK)                                                 \
                          {                                                               \
                               printf("\nStatus = %d **Failed**, line : %d\nExiting...",sts,__LINE__); \
							   getchar(); return 0;                                                     \
						  }
int main()
{
	FT_STATUS status=FT_OK;


    //Open device
	int deviceNumber=0;
	FT_HANDLE pHandle;
	status |= FT_Open(deviceNumber, &pHandle);	
	CHECKSTATUS(status);

	//Set Baud Rate 9600
	status |= FT_SetBaudRate(pHandle, 9600);
	CHECKSTATUS(status);
		
	//Test write
	char lpBuffer[] ={0x05,0x06,0x08};
	DWORD dwBytesToWrite=3;
	DWORD lpBytesWritten;
    while(1)
	{
    	//printf("\n writing..");
		status |= FT_Write(pHandle, (LPVOID *)lpBuffer,dwBytesToWrite,&lpBytesWritten);
    	printf("\n status %d, written %d",status,lpBytesWritten);
	}

	getchar();

    return 0;	
}
//eduted in mobile phone haha:




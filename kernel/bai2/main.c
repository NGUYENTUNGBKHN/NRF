
int __svc(0x00) svc_service_add(int x, int y);
int __svc(0x01) svc_service_sub(int x, int y);
int __svc(0x02) svc_service_mul(int x, int y);
int __svc(0x03) svc_service_div(int x, int y);


int x, y, z;
int main(void)
{
	x = 1;
	y = 5;
	z = svc_service_add(x, y);

	x = 9;
	y = 2;
	z = svc_service_sub(x, y);

	x = 3;
	y = 4;
	z = svc_service_mul(x, y);

	x = 12;
	y = 6;
	z = svc_service_div(x, y);
	
}

__asm void SVC_Handler(void)
{
	TST LR, #4
	ITE EQ
	MRSEQ	R0, MSP
	MRSNE 	R0, PSP
}



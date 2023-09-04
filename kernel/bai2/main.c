
int __svc(0x00) svc_service_add(int x, int y);
int __svc(0x01) svc_service_sub(int x, int y);
int __svc(0x02) svc_service_mul(int x, int y);
int __svc(0x03) svc_service_div(int x, int y);

void SVC_Handler_C(unsigned int *args);

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
	B		__cpp(SVC_Handler_C)
}

void SVC_Handler_C(unsigned int *args)
{
	unsigned int svc_number;
	svc_number = ((char*)args[6])[-2];

	switch (svc_number)
	{
	case 0:
		/* code */
		args[0] = args[0] + args[1];
		break;
	case 1:
		/* code */
		args[0] = args[0] - args[1];
		break;
	case 2:
		/* code */
		args[0] = args[0] * args[1];
		break;
	case 3:
		/* code */
		args[0] = args[0] / args[1];
		break;
	default:
		break;
	}

}





#include <stdio.h>

int main(void)
{
	FILE *ifp, *ofp;
	int num, out_size = 0;

	ifp = fopen("a.txt", "r");
	if(ifp == NULL)
	{
		printf("파일이 없습니다!\n");
		exit(1);
	}
	ofp = fopen("b.dat", "wb");
	if(ofp == NULL)
	{
		printf("파일을 열지 못했습니다!\n");
		exit(1);
	}

	fscanf(ifp, "%d", &num);
	while(!feof(ifp))
	{
		out_size += fwrite(&num, 1, sizeof(num), ofp);
		fscanf(ifp, "%d", &num);
	}

	printf("> 출력한 파일의 크기 : %d바이트\n", out_size);

	fclose(ifp);
	fclose(ofp);
	
	return 0;
}

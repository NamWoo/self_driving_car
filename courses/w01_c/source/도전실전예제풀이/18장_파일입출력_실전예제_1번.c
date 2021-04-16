#include <stdio.h>

int main(void)
{
	FILE *ifp, *ofp;
	int num, out_size = 0;

	ifp = fopen("a.txt", "r");
	if(ifp == NULL)
	{
		printf("������ �����ϴ�!\n");
		exit(1);
	}
	ofp = fopen("b.dat", "wb");
	if(ofp == NULL)
	{
		printf("������ ���� ���߽��ϴ�!\n");
		exit(1);
	}

	fscanf(ifp, "%d", &num);
	while(!feof(ifp))
	{
		out_size += fwrite(&num, 1, sizeof(num), ofp);
		fscanf(ifp, "%d", &num);
	}

	printf("> ����� ������ ũ�� : %d����Ʈ\n", out_size);

	fclose(ifp);
	fclose(ofp);
	
	return 0;
}

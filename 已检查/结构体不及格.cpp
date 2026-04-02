#include <stdio.h>
struct stu {
	int kh;
	float cj;
	char name[20], sex;
};
int main() {
	struct stu a[5] = {
		{100, 55, "AA", 'm'}, 
		{101, 96, "BB", 'm'}, 
		{102, 50, "CC", 'w'}, 
		{103, 98, "DD", 'w'}, 
		{104, 99, "EE", 'w'}
	};
	int j = 0;
	for(int i = 0; i < 5; i++) {
		if(a[i].cj < 60)
		j++;
	}
	printf("低于60分的不及格人数为：%d", j);
	return 0;
}

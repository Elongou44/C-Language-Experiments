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
	float max = a[0].cj;
	int j = 0, i = 0;
	for(; i < 5; i++) {
		if(a[i].cj > max) {
			max = a[i].cj;
			j = i;
		}
	}
	printf("最高分是：%f分\n考号：%d\n名字：%s\n性别是：%c", max, a[j].kh, a[j].name, a[j].sex);
	return 0;
}

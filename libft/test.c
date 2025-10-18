#include "libft.h"
#include <stdio.h>
#include <string.h>
#include <strings.h>
#include <bsd/string.h>
#include <ctype.h>

//static void	print_arr(int *arr, int n)
//{
//	for (int i = 0; i < n; i++)
//		printf("%d ", arr[i]);
//	printf("\n");
//} 

//static void	free_out(char **out, size_t len)
//{
//	while (len)
//		free(out[--len]);
//	free(out);
//}

//static size_t	count_words(const char *s, char c)
//{
//	size_t	word_count;
//	int		word;
//
//	word_count = 0;
//	word = 0;
//	while (*s)
//	{
//		if (!word && *s != c)
//		{
//			word = 1;
//			word_count++;
//		}
//		else if (word && *s == c)
//			word = 0;
//		s++;
//	}
//	return (word_count);
//}

//static char	toup(unsigned int indx, char c)
//{
//	if (indx % 2 == 0)
//		return (c);
//	else
//		return (ft_tolower(c));
//}

//static void	toup_v2(unsigned int indx, char* c)
//{
//	if (indx % 2 == 0)
//		return ;
//	else
//		*c = ft_tolower(*c);
//}
//
//static void print_lst_str(void *content)
//{
//	printf("%s\n", (char *)content);
//}
//
//static void print_list(t_list *lst, void (*print)(void *content))
//{
//	while (lst)
//	{
//		print(lst->content);
//		lst = lst->next;
//	}
//}
//
//static void del_lst_string(void *content)
//{
//	(void)content;
//}
//
//static void del_lst_str_malloc(void *content)
//{
//	free(content);
//}
//
//static void	ft_lst_toupper(void *content)
//{
//	char	*cont;
//
//	cont = (char *)content;
//	while (*cont)
//	{
//		*cont = ft_toupper(*cont);
//		cont++;
//	}
//}
//
//static void	*ft_lst_toupper_map(void *content)
//{
//	char	*cont;
//	char	*out; 
//	int		i;
//
//	cont = (char *)content;
//	out = malloc(ft_strlen(cont) + 1);
//	i = 0;
//	while (cont[i])
//	{
//		out[i] = ft_toupper(cont[i]);
//		i++;
//	}
//	out[i] = 0;
//	return (void *)out;
//}

int main(void)
{
	//	printf("Here ft_isalpha\n");
	//	printf("A: %d\n", ft_isalpha('A'));
	//	printf("a: %d\n", ft_isalpha('a'));
	//	printf("3: %d\n", ft_isalpha('3'));
	//	printf("z: %d\n", ft_isalpha('z'));
	//	printf("Z: %d\n", ft_isalpha('Z'));
	//	printf("+: %d\n", ft_isalpha('+'));
	//	printf("1 int: %d\n", ft_isalpha(1));
	//	printf("618 ft: %d\n", ft_isalpha(618));
	//	printf("618 norm: %d\n", isalpha(618));
//
//		printf("Here ft_isdigit\n");
//		printf("A: %d\n", ft_isdigit('A'));
//		printf("a: %d\n", ft_isdigit('a'));
//		printf("3: %d\n", ft_isdigit('3'));
//		printf("z: %d\n", ft_isdigit('z'));
//		printf("Z: %d\n", ft_isdigit('Z'));
//		printf("+: %d\n", ft_isdigit('+'));
//		printf("1 int: %d\n", ft_isdigit(1));
//
//		printf("Here ft_isalnum\n");
//		printf("A: %d\n", ft_isalnum('A'));
//		printf("a: %d\n", ft_isalnum('a'));
//		printf("3: %d\n", ft_isalnum('3'));
//		printf("z: %d\n", ft_isalnum('z'));
//		printf("Z: %d\n", ft_isalnum('Z'));
//		printf("+: %d\n", ft_isalnum('+'));
//		printf("1 int: %d\n", ft_isalnum(1));
//
		//printf("Here ft_isascii\n");
		//printf("A: %d\n", ft_isascii('A'));
		//printf("a: %d\n", ft_isascii('a'));
		//printf("3: %d\n", ft_isascii('3'));
		//printf("z: %d\n", ft_isascii('z'));
		//printf("Z: %d\n", ft_isascii('Z'));
		//printf("+: %d\n", ft_isascii('+'));
		//printf("1 int: %d\n", ft_isascii(1));
		//printf("1 int: %d\n", ft_isascii(1));
		//printf("618 ft: %d\n", ft_isascii(618));
		//printf("618 norm: %d\n", isascii(618));
		//printf("-13 ft: %d\n", ft_isascii(-13));
		//printf("-13 norm: %d\n", isascii(-13));
		//printf("-256 ft: %d\n", ft_isascii(-256));
		//printf("-256 norm: %d\n", isascii(-256));
		//printf("256 ft: %d\n", ft_isascii(256));
		//printf("256 norm: %d\n", isascii(256));
		//printf("128 ft: %d\n", ft_isascii(128));
		//printf("128 norm: %d\n", isascii(128));
		//printf("-129 ft: %d\n", ft_isascii(-129));
		//printf("-129 norm: %d\n", isascii(-129));
                                          
		//printf("ft_strlen\n");
		//printf("ft_strlen(blau): %zu\n", ft_strlen("blau"));
		//printf("ft_strlen(): %zu\n", ft_strlen(""));

//		printf("Here ft_isprint\n");
//		printf("A: %d\n", ft_isprint('A'));
//		printf("a: %d\n", ft_isprint('a'));
//		printf("3: %d\n", ft_isprint('3'));
//		printf("\\n: %d\n", ft_isprint('\n'));
//		printf("Z: %d\n", ft_isprint('Z'));
//		printf("+: %d\n", ft_isprint('+'));
//		printf("1 int: %d\n", ft_isprint(1));
//		printf("1 int: %d\n", isprint(1));
//		printf("618 ft: %d\n", ft_isascii(618));
//		printf("618 norm: %d\n", isascii(618));
//		printf("-13 ft: %d\n", ft_isprint(-13));
//		printf("-13 norm: %d\n", isprint(-13));
//		printf("-256 ft: %d\n", ft_isprint(-256));
//		printf("-256 norm: %d\n", isprint(-256));
//		printf("256 ft: %d\n", ft_isprint(256));
//		printf("256 norm: %d\n", isprint(256));
//		printf("128 ft: %d\n", ft_isprint(128));
//		printf("128 norm: %d\n", isprint(128));
//		printf("-129 ft: %d\n", ft_isprint(-129));
//		printf("-129 norm: %d\n", isprint(-129));
//
//		printf("Memset\n");
//		char *mem_arr[8];
//		int	arr[10];
//		int	arr2[10];
//		ft_memset(mem_arr, 1, 8);
//		memset(arr2, 1, 10*sizeof(int));
//		print_arr(arr, 10);
//		print_arr(arr2, 10);
//
//		printf("Bzero\n");
//		ft_bzero(arr, 10*sizeof(int));
//		bzero(arr2, 10*sizeof(int));
//		print_arr(arr, 10);
//		print_arr(arr2, 10);
//
		//printf("Memcpy\n");
//		int *ret_arr = ft_memcpy(NULL, NULL, 3);
//		int *ret_arr2 = memcpy(NULL, NULL, 3);
	//	printf("%p\n", ret_arr);
//		printf("%p\n", ret_arr2);
		//write(1, ret_arr, 3);
		//char *arr4 = "hi you d\xff""oofi";
		//char arr4[10];
		//char arr5[10];
		////int	arr3[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
		////int	arr4[10];
		////int	arr5[10];
		//int *ret_arr = ft_memcpy(arr4, arr3, 10*sizeof(char));	
		//int *ret_arr2 = memcpy(arr5, arr3, 10*sizeof(char));	
		//printf("Ft_memcpy inplace chaned:\n");
		//write(1, arr4, 10); 
		//printf("\n");
		////print_arr(arr4, 10);
		//printf("Memcpy original inplace chaned:\n");
		//write(1, arr5, 10); 
		//printf("\n");
		////print_arr(arr5, 10);
		//printf("ft_memcpy return value:\n");
		//write(1, ret_arr, 10); 
		//printf("\n");
		////print_arr(ret_arr, 10);
		//printf("Memcpy original return value:\n");
		//write(1, ret_arr2, 10); 
		//printf("\n");
		//print_arr(ret_arr2, 10);
//
//		printf("Memmove\n");
//		int	arr_ft_memmove[10] = {9, 11, 1, 15, 0, 2, 44, 32, 4, 100};
//		int	arr_memmove[10] = {9, 11, 1, 15, 0, 2, 44, 32, 4, 100};
//		int *dest_ft_memmove = &arr_ft_memmove[4];
//		int *dest_memmove = &arr_ft_memmove[4];
//		int *src_ft_memmove = &arr_ft_memmove[1];
//		int *src_memmove = &arr_memmove[1];
//		int	memsize = 0;
//		int	*dest_ft_memmove = NULL;
//		int	*dest_memmove = NULL;
//		int *src_ft_memmove = NULL;
//		int *src_memmove = NULL;
//		int *ret_ft_memmove = ft_memmove(dest_ft_memmove, src_ft_memmove, memsize*sizeof(int));	
//		int *ret_memmove = memmove(dest_memmove, src_memmove, memsize*sizeof(int));	
//		printf("Ft_memmove inplace chaned:\n");
//		print_arr(dest_ft_memmove, memsize);
//		printf("Memcpy original inplace chaned:\n");
//		print_arr(dest_memmove, memsize);
//		printf("ft_memmove return value:\n");
//		print_arr(ret_ft_memmove, memsize);
//		printf("Memcpy original return value:\n");
//		print_arr(ret_memmove, memsize);
//
//		printf("strlcpy\n");
//		char src1[20] = "halloMam4!";
//		char src2[20] = "halloMam4!";
//		char *dst1 = &src1[1];
//		char *dst2 = &src2[1];
//		unsigned int size = 4;
//
//		unsigned int lol1 = ft_strlcpy(dst1, src1, size);
//		unsigned int lol2 = strlcpy(dst2, src2, size);
//		printf("%s\n", dst1);
//		printf("%s\n", dst2);
//		printf("%d\n", lol1);
//		printf("%d\n", lol2);

		
		//char arr_ft[10] = "yosuarman\0";
		//char arr_norm[10] = "yosuarman\0";
		//int dest_pos = 2;
		//int src_pos = 0;
		//char *dest_ft_strlcpy = &arr_ft[dest_pos];
		//char *dest_strlcpy = &arr_norm[dest_pos];
		//char *src_ft_strlcpy = &arr_ft[src_pos];
		//char *src_strlcpy = &arr_norm[src_pos];
		//int buflen = 3;
		//printf("size: %d; t_strlcpy_len: %zu\n", buflen, ft_strlcpy(dest_ft_strlcpy, src_ft_strlcpy, buflen));
		//printf("size: %d; strlcpy_len: %zu\n", buflen, strlcpy(dest_strlcpy, src_strlcpy, buflen));
		//printf("ft copied: %s\n", dest_ft_strlcpy);
		//printf("norm copied: %s\n", dest_strlcpy);
//
		//printf("strlcat\n");
		//char arr_ft[] = "yosun\0aaaaaaaaaa\0";
		//char padding[20] = {0};
		//char arr_norm[] = "yosun\0aaaaaaaaaa\0";
		//int dest_pos = 0;
		//int src_pos = 0;
		//char *dest_ft_strlcat = &arr_ft[dest_pos];
		//char *dest_strlcat = &arr_norm[dest_pos];
		//char *src_ft_strlcat = &arr_ft[src_pos];
		//char *src_strlcat = &arr_norm[src_pos];
		//char dest_ft_strlcat[10] = "yosun";
		//char padding[10] = {0};
		//char dest_strlcat[10] = "yosun";
		//char *src_ft_strlcat = " Cool Guy";
		//char *src_strlcat = " Cool Guy";
		//size_t strlcat_size = 8;
		//size_t ret_ft = ft_strlcat(dest_ft_strlcat, src_ft_strlcat, strlcat_size);
		//size_t ret_norm = strlcat(dest_strlcat, src_strlcat, strlcat_size);
		//if (padding[0] == 0) printf("Padding there\n");
		//printf("strlcat_size: %zu; ft_strlcat_len: %zu\n", strlcat_size, ret_ft);
		//printf("strlcat_size: %zu; strlcat_len: %zu\n", strlcat_size, ret_norm);
		//printf("ft copied: %s\n", dest_ft_strlcat);
		//printf("norm copied: %s\n", dest_strlcat);
//
//		printf("toupper\n");
//		printf("a: %c\n", ft_toupper('a'));
//		printf("z: %c\n", ft_toupper('z'));
//		printf("3: %c\n", ft_toupper('3'));
//		printf("B: %c\n", ft_toupper('B'));
//
//		printf("tolower\n");
//		printf("A: %c\n", ft_tolower('A'));
//		printf("Z: %c\n", ft_tolower('Z'));
//		printf("3: %c\n", ft_tolower('3'));
//		printf("b: %c\n", ft_tolower('b'));
//
		printf("strchr\n");
		char *strchr_inpt = "al\xFF""ejha";
		int	strchr_int = 618;
		printf("Find h in alloha ft: %s\n", ft_strchr(strchr_inpt, strchr_int));
		printf("Find h in alloha norm: %s\n", strchr(strchr_inpt, strchr_int));
//
//		printf("strrchr\n");
//		char *strrchr_inpt = "al\xff""ejha\xff""j";
//		int	strrchr_int = 255;
//		printf("Find h in alloha ft: %s\n", ft_strrchr(strrchr_inpt, strrchr_int));
//		printf("Find h in alloha norm: %s\n", strrchr(strrchr_inpt, strrchr_int));
//
//		printf("strncmp\n");
//		char *strncmp_1 = "hey";
//		char *strncmp_2 = "hepeeeee";
//		size_t	strncmp_int= 3;
//		printf("ft: %d\n", ft_strncmp(strncmp_1, strncmp_2, strncmp_int));
//		printf("Norm: %d\n", strncmp(strncmp_1, strncmp_2, strncmp_int));
//
//		printf("memchr\n");
//		char *memchr_inpt = "allejha";
//		int	memchr_int= -100;
//		size_t memchr_size = 8;
//		void *ft_result = ft_memchr(memchr_inpt, memchr_int, memchr_size);
//		void *std_result = memchr(memchr_inpt, memchr_int, memchr_size);
//		printf("Find %c in %s ft: %s \n", memchr_int, memchr_inpt, (char *)ft_result);
//		printf("Find %c in %s std: %s \n", memchr_int, memchr_inpt, (char *)std_result);
//
//		printf("memcmp\n");
//		char *memcmp_s1 = "accd";
//		char *memcmp_s2 = "abcd";
//		size_t memcmp_size = -100000;
//		int std_res = memcmp(memcmp_s1, memcmp_s2, memcmp_size);
//		int ft_res = ft_memcmp(memcmp_s1, memcmp_s2, memcmp_size);
//		printf("memcmp result: %d\n", std_res);
//		printf("ft_memcmp  result: %d\n", ft_res);
//
		//printf("strnstr\n");
		//char *strnstr_s1 = NULL;
		//char *strnstr_s2 = "fake";
		//size_t strnstr_size = 3;
		////char *std_res_strnstr = strnstr(strnstr_s1, strnstr_s2, strnstr_size);
		//char *res_strnstr = ft_strnstr(strnstr_s1, strnstr_s2, strnstr_size);
		////printf("strnstr result: %s\n", std_res_strnstr);
		//printf("ft_strnstr  result: %s\n", res_strnstr);
//		
//		printf("atoi\n");
//		char *atoi_inpt = "     --21474836488";
//		printf("std: %d\n", atoi(atoi_inpt));
//		printf("ft: %d\n", ft_atoi(atoi_inpt));
//
//		printf("Calloc\n");
//		char *ptr = malloc(0);
//		*ptr = 'c';
//		*(ptr + 1) = 'c';
//		printf("%p\n", ptr);
//		printf("%c\n", *ptr);
//		printf("%c\n", *(ptr + 1));
//		free(ptr);
//		size_t calloc_size = 4;
//		size_t calloc_count = 5;
//		int *calloc_ft = ft_calloc(calloc_size, calloc_count);
//		int *calloc_norm = calloc(calloc_size, calloc_count);
//		printf("ft: %p\n", calloc_ft);
//		print_arr(calloc_ft, calloc_size);
//		printf("norm: %p\n", calloc_norm);
//		print_arr(calloc_norm, calloc_size);
//		if (calloc_ft)
//			free(calloc_ft);
//		if(calloc_norm)
//			free(calloc_norm);
//
//		printf("strdup\n");
//		const char *strdup_s = "";
//		char *strdup_ft = ft_strdup(strdup_s);
//		printf("ft: %s\n", strdup_ft);
//		char *strdup_norm = strdup(strdup_s);
//		printf("norm: %s\n", strdup_norm);
//		if (strdup_ft)
//			free(strdup_ft);
//		if (strdup_norm)
//			free(strdup_norm);
//
//		printf("substr\n");
//		const char *substr_s = "Who?";
//		size_t substr_len = 2;
//		unsigned int substr_start = 2;	
//		char *substr_ft = ft_substr(substr_s, substr_start, substr_len);
//		printf("ft: %s\n", substr_ft);
//		if (substr_ft)
//			free(substr_ft);
//
//		printf("strjoin\n");
//		const char *strjoin_1 = "";
//		const char *strjoin_2 = "";
//		printf("S1: %s\n", strjoin_1);
//		printf("S2: %s\n", strjoin_2);
//		char *strjoin_res = ft_strjoin(strjoin_1, strjoin_2);
//		printf("Res: %s\n", strjoin_res);
//		if (strjoin_res)
//			free(strjoin_res);
//		
//		printf("strtrim\n");
//		const char *strtrim_s = "rar";
//		const char *strtrim_set = "ra";
//		char *strtrim_out = ft_strtrim(strtrim_s, strtrim_set);
//		printf("In: %sEND\n", strtrim_s);
//		printf("Out: %sEND\n", strtrim_out);
//		if (strtrim_out)
//			free(strtrim_out);

		//printf("split\n");
		//char *split_in = " hi";
		//char **out = ft_split(split_in, '\0');
		//printf("input: %s\n", split_in);
		//printf("out: %p\n", out);
		//size_t wc = count_words(split_in, ' ');
		//for (size_t i = 0; i < wc; i++)
		//	printf("out[%zu]: %s\n", i, out[i]);
		//free_out(out, wc);

		//printf("itoa\n");
		//int itoa_in = 0;
		//char *ft_itoa_out = ft_itoa(itoa_in);
		//printf("ft_itoa: %s\n", ft_itoa_out);
		//if (ft_itoa_out)
		//	free(ft_itoa_out);

		//printf("strmapi\n");
		//const char *strmapi_in = "Y? WHA0AAAPPP";
		//char *strmapi_out = ft_strmapi(strmapi_in, toup);
		//printf("In: %s\n", strmapi_in);  
		//printf("Out: %s\n", strmapi_out);
		//if (strmapi_out)
		//	free(strmapi_out);

		//printf("striteri\n");
		//char striteri_in[] = "";
		//ft_striteri(striteri_in, toup_v2);
		//printf("In: %s\n", striteri_in);  
		//printf("Out: %s\n", striteri_in);

		//printf("putchar\n");
		//ft_putchar_fd('c', 1);
		//printf("END\n");

		//printf("putstr\n");
		//ft_putstr_fd("  well this is just text", 1);
		//printf("END\n");

		//printf("putend\n");
		//ft_putendl_fd("  well this is just text", 1);
		//
		//printf("putnbr\n");
		//ft_putnbr_fd(INT_MIN, 1);
		//printf("\n");
		//ft_putnbr_fd(INT_MAX, 1);
		//printf("\n");
		//ft_putnbr_fd(0, 1);
		//printf("\n");
	
//		printf("linked list stuff\n");
//		char *ll_str = malloc(6);
//		ft_strlcpy(ll_str, "hello", 6); 
//		t_list	*list = ft_lstnew("hello");
//		t_list	*list2 = ft_lstnew(ll_str);
//		print_list(list, print_lst_str);
//		print_list(list2, print_lst_str);
//		ft_lstdelone(list, del_lst_string);
//		ft_lstdelone(list2, del_lst_str_malloc);
//	
//		//now longer list
//		t_list	*tmp_list;
//		//first element
//		char *ll1_str = malloc(6);
//		ft_strlcpy(ll1_str, "hello", 6); 
//		t_list	*list3 = ft_lstnew(ll1_str);
//		//second element prepend
//		char *ll2_str = malloc(6);
//		ft_strlcpy(ll2_str, "David", 6);
//		tmp_list = ft_lstnew(ll2_str);
//		ft_lstadd_front(&list3, tmp_list); 
//		//third element, postpend
//		char *ll3_str = malloc(6);
//		ft_strlcpy(ll3_str, "world", 6);
//		tmp_list = ft_lstnew(ll3_str);
//		ft_lstadd_back(&list3, tmp_list);
//		//print list as is
//		print_list(list3, print_lst_str);
//		//print size of list
//		printf("%d\n", ft_lstsize(list3));
//		//print last elements content of list
//		printf("%s\n", (char *)(ft_lstlast(list3))->content);
//		//apply striteri to list
//		ft_lstiter(list3, ft_lst_toupper);
//		print_list(list3, print_lst_str);
//		//apply lstmap
//		t_list	*list4 = ft_lstmap(list3, ft_lst_toupper_map, del_lst_str_malloc);
//		print_list(list4, print_lst_str);
//		//free list incl content
//		ft_lstclear(&list3, del_lst_str_malloc);
//		ft_lstclear(&list4, del_lst_str_malloc);


		//ft_lstclear(&list, del_lst_string);

}

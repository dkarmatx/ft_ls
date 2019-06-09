all:
	gcc -I libft/includes *.c libft/srcs/*.c

debug:
	gcc -I libft/includes *.c libft/srcs/*.c -g

bin:
	gcc -I libft/includes *.c libft/srcs/*.c -o /Users/hgranule/bin/ft_ls

clean_bin:
	rm -rf /Users/hgranule/bin/ft_ls
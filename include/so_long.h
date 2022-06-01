#ifndef SO_LONG
# define SO_LONG

#include <mlx.h>
#include <stdlib.h>
#include <X11/XKBlib.h>
#include <X11/X.h>
#include <stdio.h>
#include <fcntl.h>

#include <unistd.h>
#include "../libft/include/libft.h"
#include "../gnl/get_next_line.h"

typedef struct s_mapline
{
	char *line;
	struct s_mapline *next;
}t_mapline;

typedef struct s_valid_p
{
	int players;
	int wall;
	int empty;
	int exit;
	int collectible;
}t_valid_p;

t_mapline	*newline(char *s);
void		add_line(t_mapline **lines, t_mapline *newline);
int			check_ber(char *s);
int			check_len(char *s, int len, t_mapline **lines);
int			str_to_lines(char *s, t_mapline **lines);
int			parse(int ac, char **av, t_mapline **lines);
void		ft_free(t_mapline **lst);
int			check_wall(char *line, int i, t_mapline *lines);

#endif
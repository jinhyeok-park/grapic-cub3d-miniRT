#ifndef COLOR_H
#define COLOR_H

typedef struct s_color3
{
    double  r;
    double  g;
    double  b;
} t_color3;

t_color3    color_plus(t_color3 *color, t_color3 *color2);
t_color3    color_multi_scala(t_color3 *color, double val);

#endif


#include <stdio.h>

#define WIDTH  61
#define HEIGHT 21

typedef struct {
    double a;
    double b;
    double c;
} Parabola;

static double f(Parabola p, double x) {
    return p.a * x * x + p.b * x + p.c;
}

static int col_of(double x, double xmin, double xmax) {
    double t = (x - xmin) / (xmax - xmin);
    int c = (int)(t * (WIDTH - 1) + 0.5);
    if (c < 0) c = 0;
    if (c >= WIDTH) c = WIDTH - 1;
    return c;
}

static int row_of(double y, double ymin, double ymax) {
    double t = (y - ymin) / (ymax - ymin);
    return (int)((1.0 - t) * (HEIGHT - 1) + 0.5);
}

int main(void) {
    Parabola p;

    printf("Enter coefficient a: ");
    if (scanf("%lf", &p.a) != 1 || p.a == 0.0) return 0;

    printf("Enter coefficient b: ");
    if (scanf("%lf", &p.b) != 1) return 0;

    printf("Enter coefficient c: ");
    if (scanf("%lf", &p.c) != 1) return 0;

    /* Vertex */
    double vx = -p.b / (2.0 * p.a);
    double vy = f(p, vx);

    /* Fixed textbook window */
    double x_half = 8.0;
    double y_half = 8.0;

    double xmin = vx - x_half;
    double xmax = vx + x_half;
    double ymin = vy - y_half;
    double ymax = vy + y_half;

    char grid[HEIGHT][WIDTH];
    for (int r = 0; r < HEIGHT; r++)
        for (int c = 0; c < WIDTH; c++)
            grid[r][c] = ' ';

    /* Axes */
    if (0.0 >= ymin && 0.0 <= ymax) {
        int xr = row_of(0.0, ymin, ymax);
        for (int c = 0; c < WIDTH; c++) grid[xr][c] = '-';
    }

    if (0.0 >= xmin && 0.0 <= xmax) {
        int yc = col_of(0.0, xmin, xmax);
        for (int r = 0; r < HEIGHT; r++) grid[r][yc] = '|';
    }

    if (0.0 >= xmin && 0.0 <= xmax && 0.0 >= ymin && 0.0 <= ymax) {
        int xr = row_of(0.0, ymin, ymax);
        int yc = col_of(0.0, xmin, xmax);
        grid[xr][yc] = '+';
    }

    /* Curve (skip out-of-range points) */
    for (int c = 0; c < WIDTH; c++) {
        double x = xmin + (xmax - xmin) * c / (WIDTH - 1);
        double y = f(p, x);

        if (y < ymin || y > ymax) continue;   /* CRITICAL FIX */

        int r = row_of(y, ymin, ymax);
        if (r >= 0 && r < HEIGHT)
            grid[r][c] = '*';
    }

    /* Vertex */
    int vr = row_of(vy, ymin, ymax);
    int vc = col_of(vx, xmin, xmax);
    grid[vr][vc] = 'V';

    printf("\nParabola y = ax^2 + bx + c\n");
    printf("Vertex (%.2f, %.2f)\n\n", vx, vy);

    for (int r = 0; r < HEIGHT; r++) {
        for (int c = 0; c < WIDTH; c++)
            putchar(grid[r][c]);
        putchar('\n');
    }

    return 0;
}


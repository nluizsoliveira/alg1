#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct dot {
    int x;
    int y;
} Dot;

typedef struct path {
    int size;
    Dot* all_dots;
    double distance;
} Path;

Path* create_path(int size) { 
    Path* path = malloc(sizeof(Path));
    path->size = size;
    path->all_dots = malloc(size * sizeof(int));
    path->distance = 0; 
    return path;
}

int main () {
    int path_size;
    scanf("%d", &path_size);

    Path* path = create_path(path_size);
    
    for(int dot = 0; dot < path->size; dot++) { 
        scanf(
            "%d %d",
            &path->all_dots[dot].x,
            &path->all_dots[dot].y
        );
    }

    for(int dot = 1; dot < path-> size; dot++) {
        int Xf = path->all_dots[dot].x;
        int Xi = path->all_dots[dot-1].x;
        int Yf = path->all_dots[dot].y;
        int Yi = path->all_dots[dot-1].y;

        path->distance = path->distance + sqrt((Xf - Xi)*(Xf - Xi) + (Yf - Yi)*(Yf - Yi));
    }

    printf("%lf", path->distance);
}
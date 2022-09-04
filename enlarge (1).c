/* Francis Lu
 * 9080557540
 */

#include <stdio.h>


//struct function to create the x and y coordinate points
struct point{ 
  int x_coordinate; //x coordinate
  int y_coordinate; //y coordinate
};

//struct function to create the rectangle
struct rect{
  struct point upper_right_corner;// place upper right 
  struct point lower_left_corner; //place lower left
  
};

void Enlarge_Rectangle(struct rect *r, struct point p){
  //if loop to stretch upper right corner x if necessary
  if((p.x_coordinate) > (r->upper_right_corner.x_coordinate)){
    r->upper_right_corner.x_coordinate = p.x_coordinate;
  }
  //if loop to stretch upper right y if necessary
  if((p.y_coordinate) > (r->upper_right_corner.y_coordinate)){
    r->upper_right_corner.y_coordinate = p.y_coordinate;
  }
  //if loop to stretch lower left x if necessary
  if((p.x_coordinate) < (r->lower_left_corner.x_coordinate)){
    r->lower_left_corner.x_coordinate = p.x_coordinate;
  }
  //if loop to stretch lower left y if necessary
  if((p.y_coordinate) < (r->lower_left_corner.y_coordinate)){
    r->lower_left_corner.y_coordinate = p.y_coordinate;
  }
}

//main function to test if rectangle can be stretched.
int main() {
  struct rect r;
  struct point p;
  
  //original rectangle test
  r.upper_right_corner.x_coordinate = 1;
  r.upper_right_corner.y_coordinate = 1;
  
  r.lower_left_corner.y_coordinate = 0;
  r.lower_left_corner.x_coordinate = 0;
  
  printf("Original Rectangle Location: lower left corner:(%d, %d) , upper right corner:(%d, %d)\n", r.lower_left_corner.x_coordinate, r.lower_left_corner.y_coordinate, r.upper_right_corner.x_coordinate, r.upper_right_corner.y_coordinate); 
  
  //testing if rectangle stretches to -1,1;
  p.x_coordinate = -1;
  p.y_coordinate = 1;
  
  Enlarge_Rectangle(&r, p);
  printf("New Stretched Rectangle Location: lower left corner:(%d, %d) , upper right corner:(%d, %d)\n", r.lower_left_corner.x_coordinate, r.lower_left_corner.y_coordinate, r.upper_right_corner.x_coordinate, r.upper_right_corner.y_coordinate); 
  
  //test for point (2,3);
  p.x_coordinate = 2;
  p.y_coordinate = 3;
  
  Enlarge_Rectangle(&r, p);
  printf("New Stretched Rectangle Location: lower left corner:(%d, %d) , upper right corner:(%d, %d)\n", r.lower_left_corner.x_coordinate, r.lower_left_corner.y_coordinate, r.upper_right_corner.x_coordinate, r.upper_right_corner.y_coordinate); 
  
  
}

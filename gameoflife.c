#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <unistd.h>

sf::RenderWindow window(sf::VideoMode(800, 800), "Game of Life!");	
void strcp(int nextgen[800][800],int currentgen[800][800]);
void generator(int nextgen[800][800],int currentgen[800][800]);
void draw(int nextgen[800][800]);
int check(int nextgen[800][800]);

int main(){

	int n,k,cell_x,cell_y;
	register int i,j;
	int currentgen[800][800];
	int nextgen[800][800];
	for(i = 0;i < 800;i++){
		for(j = 0; j < 800; j++){
			currentgen[i][j] = 0;
			nextgen[i][j] = 0;
		}
	}

	printf("Enter how much cells you want to input:");
	scanf("%d",&n);
	for(k = 0;k < n;k++){
		printf("Enter cell x:");
		scanf("%d",&cell_x);
		printf("Enter cell y:");
		scanf("%d",&cell_y);
		nextgen[cell_x][cell_y] = 1;
	}   	
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
      	strcp(nextgen,currentgen);
		generator(nextgen,currentgen);
		draw(nextgen);
        window.display();
        sleep(0.1);
    }
	printf("\nSorry all the cells died\n");

	return 0;
}
void strcp(int nextgen[800][800],int currentgen[800][800]){
	printf("STRCP\n");
	register int i=0,j=0;
	for(i = 0; i < 800; i++){
		for(j = 0;j < 800;j++){
			currentgen[i][j] = nextgen[i][j];
		}
	}
}

void generator(int nextgen[800][800],int currentgen[800][800]){
	printf("GENERATOR\n");
	register int i,j;
	int count_neighbor,cur_x,cur_y;
	for(i = 0; i < 800; i++){
		for(j = 0;j < 800;j++){
			count_neighbor = 0;
			if(currentgen[i][j] == 1){
				for(cur_x = i - 1; cur_x <= i + 1 ;cur_x++){
					for (cur_y = j - 1;cur_y <= j + 1;cur_y++){
						if (currentgen[cur_x][cur_y] == 1){
							count_neighbor++;
						}
					}
				}
				if(count_neighbor < 2){
					nextgen[i][j] == 0;
				}else if (count_neighbor >= 2 && count_neighbor <= 3){
					nextgen[i][j] = 1;
				}else{
					nextgen[i][j] == 0;
				}
			}else{
				for(cur_x = i - 1; cur_x <= i + 1 ;cur_x++){
					for (cur_y = j - 1;cur_y <= j + 1;cur_y++){
						if (currentgen[cur_x][cur_y] == 1){
							count_neighbor++;
						}
					}
				}
				if(count_neighbor == 3){
					nextgen[i][j] = 1;
				}
			}

		}
	}
}

void draw(int nextgen[800][800]){
	printf("DRAW\n");
	sf::RectangleShape pixel(sf::Vector2f(1,1));
	register int i,j;
	for(i = 0;i < 800;i++){
		for (j = 0; j < 800; j++){
			if(nextgen[i][j] == 1){
				pixel.setPosition(i,j);
				window.draw(pixel);
			}
		}
	}
}

int check(int nextgen[800][800]){
	printf("CHECK\n");
	register int i,j;
	for(i = 0;i < 800;i++){
		for (j = 0; j < 800; j++){
			if(nextgen[i][j] == 1){
				return 1;
			}
		}
	}
	return 0;
}

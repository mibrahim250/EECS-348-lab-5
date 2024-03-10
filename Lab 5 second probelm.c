




int main(){



    int score;
    
    while (1) {
        
        printf("Enter 0 or 1 to STOP\n");
        printf("Enter the NFL score: ");
        scanf("%d", &score);

       
        if (score <= 1)
            break;

      
        printf("possible combinations of scoring plays:\n");

      
        for (int td = 0; td * 6 <= score; td++) {
            for (int fg = 0; fg * 3 <= score - td * 6; fg++) {
                for (int safety = 0; safety * 2 <= score - td * 6 - fg * 3; safety++) {
                    int totalScore = td * 6 + fg * 3 + safety * 2;
                    
                  
                    if (totalScore == score) {
                        printf("%d TD + %dpt, %d TD + %dpt, %d TD + %dpt, %d TD, %d 3pt FG, %d Safety\n", td, 6, td, 7, td, 8, td, fg, safety);
                    }
                }
            }
        }
    }

    return 0;


}
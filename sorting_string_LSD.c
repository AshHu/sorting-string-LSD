#include <stdio.h>
#include <stdlib.h>

int main(int argc, const char * argv[]) {
    char in_fn[50], out_fn[50], buffer[1024], data[1000][22];
    int i, j, k, row=0;
    FILE *input_f, *output_f;
    printf("Please specify the input file (default = f.txt): ");
    scanf("%s", &in_fn);
    printf("Please specify the ouput file (default = g.txt): ");
    scanf("%s", &out_fn);
    input_f = fopen(in_fn,"r"); // read mode
    output_f = fopen(out_fn, "w");
    
    input_f = fopen("f.txt", "r");
    output_f = fopen("g.txt", "w");
    if(!input_f)
    {
        perror("Error while opening the file.\n");
        exit(EXIT_FAILURE);
    }
    if(!output_f) {
        perror("Error while writing the file.\n");
        exit(EXIT_FAILURE);
    }
    while(fgets(buffer, sizeof(buffer), input_f) != NULL){
        for(i=0;i<22;i++) data[row][i]=buffer[i];
        row++;
    }

    int charToint[row], p[row];
    for(i=0;i<row;i++) p[i]=i; // initializa p[row]
    for(k=20;k>=0;k--){
        int count[27]={0}, bucket[27][1000], c=0, m=0;
        for(i=0;i<27;i++)
            for(j=0;j<21;j++)
                bucket[i][j]=-1;
        for(i=0;i<row;i++) {
            charToint[m]=data[p[i]][k]; // store the asci code in charToint
            m++;
        }
        for(i=0;i<row;i++){
            if(charToint[i]==32) bucket[0][count[0]++]=p[i]; // if it's a space, bring it to the front
            else if(charToint[i]==65) bucket[1][count[1]++]=p[i]; // A
            else if(charToint[i]==66) bucket[2][count[2]++]=p[i]; // B
            else if(charToint[i]==67) bucket[3][count[3]++]=p[i]; // C
            else if(charToint[i]==68) bucket[4][count[4]++]=p[i]; // D
            else if(charToint[i]==69) bucket[5][count[5]++]=p[i]; // E
            else if(charToint[i]==70) bucket[6][count[6]++]=p[i]; // F
            else if(charToint[i]==71) bucket[7][count[7]++]=p[i]; // G
            else if(charToint[i]==72) bucket[8][count[8]++]=p[i]; // H
            else if(charToint[i]==73) bucket[9][count[9]++]=p[i]; // I
            else if(charToint[i]==74) bucket[10][count[10]++]=p[i]; // J
            else if(charToint[i]==75) bucket[11][count[11]++]=p[i]; // K
            else if(charToint[i]==76) bucket[12][count[12]++]=p[i]; // L
            else if(charToint[i]==77) bucket[13][count[13]++]=p[i]; // M
            else if(charToint[i]==78) bucket[14][count[14]++]=p[i]; // N
            else if(charToint[i]==79) bucket[15][count[15]++]=p[i]; // O
            else if(charToint[i]==80) bucket[16][count[16]++]=p[i]; // P
            else if(charToint[i]==81) bucket[17][count[17]++]=p[i]; // Q
            else if(charToint[i]==82) bucket[18][count[18]++]=p[i]; // R
            else if(charToint[i]==83) bucket[19][count[19]++]=p[i]; // S
            else if(charToint[i]==84) bucket[20][count[20]++]=p[i]; // T
            else if(charToint[i]==85) bucket[21][count[21]++]=p[i]; // U
            else if(charToint[i]==86) bucket[22][count[22]++]=p[i]; // V
            else if(charToint[i]==87) bucket[23][count[23]++]=p[i]; // W
            else if(charToint[i]==88) bucket[24][count[24]++]=p[i]; // X
            else if(charToint[i]==89) bucket[25][count[25]++]=p[i]; // Y
            else if(charToint[i]==90) bucket[26][count[26]++]=p[i]; // Z
        }
        j=0;
        for(i=0;i<27;i++){
            for(j=0;j<21;j++){
                if(bucket[i][j]==-1) break;
                p[c] = bucket[i][j];
                c++;
            }
        }
    }
    /*for(i=0;i<row;i++)
        printf("%d ", p[i]);*/
    for(j=0;j<row;j++){
        for(i=0;i<22;i++)
            fprintf(output_f, "%c", data[p[j]][i]);
        fprintf(output_f, "\n");
    }
    fclose(input_f);
    fclose(output_f);
    return 0;
}

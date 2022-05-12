#include <stdio.h>
int main(void)
{
 //何回計算するか
    int num, i;
    printf("何回計算を行いますか :");
    scanf("%d", &num);

 //装置の共鳴周波数の設定
    int MHz;
    printf("共鳴周波数(整数値) [MHz]:");
    scanf("%d", &MHz);
    printf("\n");

 //計算と結果の出力    
    for (i = 0; i < num; i++){

        int proton, coupling;
        double chemshift, J, Js, Jd, Jt, peaks, peakd, peakt, peakq, peakr;

     //プロトンの数を入力
        printf("プロトン数を入力してください[nH]:");
        scanf("%d", &proton);

     //カップリングの種類を数字で読み込む
        printf("s:1, d:2, t:3, q:4, quin:5, sex:6, sep:7, multi:10\ndd:22, dt:23, dq:24, td:32, tt:33, ddd:222\nカップリング:");
        scanf("%d", &coupling);

     //値の読み込みとケミカルシフトの計算
        if (coupling == 1) {
            printf("ピーク位置を入力してください[ppm] :");
                scanf("%lf", &peaks);
            chemshift = peaks;
            
            //結果の表示
            printf("\x1b[36m");
            printf("%.2f (s, %dH)\n\n", chemshift, proton);
            printf("\x1b[0m");
        }
        else if (coupling == 10){
            printf("ピーク位置を高周波数(低磁場)側から順に入力してください[ppm]\n");
                printf("peak 左端 :");   scanf("%lf", &peaks);
                printf("peak 右端 :");   scanf("%lf", &peakd);
            
            //結果の表示
            printf("\x1b[36m");
            printf("%.2f~%.2f (m, %dH)\n\n", peaks, peakd, proton);
            printf("\x1b[0m");
        }
        else if (coupling == 2 || coupling == 4 || coupling == 6) {
            printf("ピーク位置を高周波数(低磁場)側から順に入力してください[ppm]\n");
                printf("peak 左端 :");   scanf("%lf", &peaks);
                printf("peak 右端 :");   scanf("%lf", &peakd);
            chemshift = (peaks + peakd) / 2;
            J = (peaks - peakd) * MHz / (coupling - 1);

             //結果の表示
            printf("\x1b[36m"); 
            if (coupling == 2){
                printf("%.2f (d, J = %.2f Hz, %dH)\n\n", chemshift, J, proton);
            }
            else if (coupling == 4){
                printf("%.2f (q, J = %.2f Hz, %dH)\n\n", chemshift, J, proton);
            }
            else if (coupling == 6){
                printf("%.2f (sex, J = %.2f Hz, %dH)\n\n", chemshift, J, proton);
            }
            printf("\x1b[0m");
        }
        else if (coupling == 3 || coupling == 5 || coupling == 7) {
            printf("3つのピーク位置を高周波数(低磁場)側から順に入力してください[ppm] :\n");
                printf("peak 左端 :");   scanf("%lf", &peaks);
                printf("peak 中央 :");   scanf("%lf", &peakt);
                printf("peak 右端 :");   scanf("%lf", &peakd);
            chemshift = peakt;
            J = (peaks - peakd) * MHz / (coupling - 1);
            
            //結果の表示
            printf("\x1b[36m");
            if (coupling == 3)
                printf("%.2f (t, J = %.2f Hz, %dH)\n\n", chemshift, J, proton);
            else if (coupling == 5)
                printf("%.2f (quin, J = %.2f Hz, %dH)\n\n", chemshift, J, proton);
            else if (coupling == 7)
                printf("%.2f (sep, J = %.2f Hz, %dH)\n\n", chemshift, J, proton);
            printf("\x1b[0m");
        }
        else if (coupling == 22){
            printf("すべてのピーク位置を高周波数側から順に入力してください[ppm] :\n");
                printf("peak 左端 :");  scanf("%lf", &peaks);
                printf("peak 左端から2つ目 :");   scanf("%lf", &peakd);
                printf("peak 左端から3つ目 :");   scanf("%lf", &peakt);
                printf("peak 左端から4つ目 :");   scanf("%lf", &peakq);
            chemshift = (peaks + peakq) / 2;
            Js = (peaks - peakt) * MHz;
            Jd = (peaks - peakd) * MHz;
            
            //結果の表示
            printf("\x1b[36m");
            printf("%.2f (dd, J = %.2f, %.2f Hz, %dH)\n\n", chemshift, Js, Jd, proton);
            printf("\x1b[0m");
        }
        else if (coupling == 23){
            printf("最も高周波数側のピークから2つとそこから一つとばしたピーク, 最も低周波数側のピークの計4つのピーク位置を順に入力してください[ppm] :\n");
                printf("peak 左端 :");  scanf("%lf", &peaks);
                printf("peak 左端から2つ目 :");   scanf("%lf", &peakd);
                printf("peak 左端から4つ目 :");   scanf("%lf", &peakt);
                printf("peak 右端 :");   scanf("%lf", &peakq);
            chemshift = (peaks + peakq) / 2;
            Js = (peaks - peakt) * MHz;
            Jd = (peaks - peakd) * MHz;

            //結果の表示
            printf("\x1b[36m");
            printf("%.2f (dt, J = %.2f, %.2f Hz, %dH)\n\n", chemshift, Js, Jd, proton);
            printf("\x1b[0m");
        }
        else if (coupling == 24 || coupling == 32 || coupling == 33){
            printf("最も高周波数側のピークから3つ, 最も低周波数側のピークの計4つのピーク位置を順に入力してください[ppm] :\n");
                printf("peak 左端 :");  scanf("%lf", &peaks);
                printf("peak 左端から2つ目 :");   scanf("%lf", &peakd);
                printf("peak 左端から3つ目 :");   scanf("%lf", &peakt);
                printf("peak 右端 :");   scanf("%lf", &peakq);
            chemshift = (peaks + peakq) / 2;
            Js = (peaks - peakt) * MHz;
            Jd = (peaks - peakd) * MHz;

            //結果の表示
            printf("\x1b[36m");
            if (coupling == 24)
                printf("%.2f (dq, J1 = %.2f, %.2f Hz, %dH)\n\n", chemshift, Js, Jd, proton);
            else if (coupling == 32)
                printf("%.2f (td, J1 = %.2f, %.2f Hz, %dH)\n\n", chemshift, Js, Jd, proton);
            else if (coupling == 33)
                printf("%.2f (tt, J1 = %.2f, %.2f Hz, %dH)\n\n", chemshift, Js, Jd, proton);
            printf("\x1b[0m");
        }
        else if (coupling == 222){
            printf("最も高周波数側のピークから4つ, 最も低周波数側のピークの計5つのピーク位置を順に入力してください[ppm] :\n");
                printf("peak 左端 :");  scanf("%lf", &peaks);
                printf("peak 左端から2つ目 :");   scanf("%lf", &peakd);
                printf("peak 左端から3つ目 :");   scanf("%lf", &peakt);
                printf("peak 左端から4つ目 :");   scanf("%lf", &peakq);
                printf("peak 右端 :");  scanf("%lf", &peakr);
            chemshift = (peaks + peakr) / 2;
            Js = (peaks - peakq) * MHz;
            Jd = (peaks - peakt) * MHz;
            Jt = (peaks - peakd) * MHz;

            //結果の表示
            printf("\x1b[36m");
            printf("%.2f (ddd, J = %.2f, %.2f, %.2f Hz, %dH)\n\n", chemshift, Js, Jd, Jt, proton);
            printf("\x1b[0m");
        }
    }

    return 0;
}
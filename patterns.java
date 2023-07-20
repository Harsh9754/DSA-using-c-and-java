public class patterns {

    static void pattern(int n){
        for (int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                System.out.print("*"+" ");
            }
            System.out.println();
        }
    }
    /*pyramids......................................... */
    static void pattern2(int n){
       for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            System.out.print("*"+" ");
        }
        System.out.println();
       }
    }
    /*pyramids of numbers......................................... */
    static void pattern3(int n){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=i;j++){
                System.out.print(j+" ");
            }
            System.out.println();
        }
    }

 /*pyramids of repeated numbers......................................... */

   static void pattern4(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            System.out.print(i+" ");
        }
        System.out.println();
    }
   }

 /*pyramids of reversed * pattern......................................... */
static void pattern5(int n){
      for(int i=1;i<=n;i++){
      for(int j=1;j<=n-i+1;j++){
            System.out.print(j+" ");
       }
        System.out.println();
       }
    }
/*half diamond star pattern......................... */
   static void p10(int n){
    for(int i=1;i<=2*n-1;i++){
        int stars=i;
        if(i>n) stars = 2*n-i;

        for(int j=1;j<=stars;j++){
            System.out.print("*");
        }
        System.out.println();
    }
   }
/*increasing letter with triangle........................... */
static void p14(int n){
   for(int i=0;i<n;i++){
        for(char ch ='A';ch<='A'+i;ch++){
            System.out.print(ch+" ");
        }
System.out.println();
    }
}
/*pattern 13 printing numbers in increase........................... */
static void p13(int n){
    int num =1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            System.out.print(num+" ");
            num = num+1;
        }
        System.out.println();
    }
}
/* pattern 15 reversing letters ..................................... */
static void p15(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            System.out.print(" ");
        }
        for(int j=0;j<2*n-(2*i+1);j++){
            System.out.print("*"+"");
        }
        for(int j=0;j<i;j++){
            System.out.print(" ");
        }
        System.out.println();
    }
    // for(int i=0;i<n;i++){
    //     for(char ch = 'A';ch<='A'+(n-i-1);ch++){
    //         System.out.print(ch+" ");
    //     }
    //     System.out.println();
    //     }
}
  /*pattern 16 alpha ramp pattern ................................... */
  static void p16(int n){
    for(int i=0;i<n;i++){
        for(int j=0;j<=i;j++){
            char ch =(char) ('A'+i);
            System.out.print(ch+" ");
        }
        System.out.println();
        }
  }

static void pyr09(int n){
    for(int i =0;i<n;i++){
        for(int j=0;j<n-i-1;j++){
            System.out.print(" ");
        }
        for(int j=0;j<2*i+1;j++){
            System.out.print("*"+"");
        }
        for(int j=0;j<n-i-1;j++){
            System.out.print(" ");
        }
        System.out.println();
    }

  }  



  public static void main(String[] args) {
    int n=5;
    p10(n);

 }
}


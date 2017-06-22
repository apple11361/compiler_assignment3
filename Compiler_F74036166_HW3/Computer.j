.class public main
.super java/lang/Object
.method public static main([Ljava/lang/String;)V
.limit stack 10
.limit locals 10
ldc 4.000000
fstore 0
ldc 0.0
fstore 1
ldc 4.000000
ldc 10.000000
fmul 
fstore 1
ldc 40.000000
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
ldc 40.000000
ldc 3.000000
ldc 2.000000
fadd 
ldc 5.000000
fdiv 
fstore 0
ldc 8.000000
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(F)V
ldc "Compile Success!"
getstatic java/lang/System/out Ljava/io/PrintStream;
swap
invokevirtual java/io/PrintStream/println(Ljava/lang/String;)V
return
.end method

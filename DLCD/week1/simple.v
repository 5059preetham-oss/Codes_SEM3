module simple(E,D,A,B,C);
output D,E;
input A,B,C;
and a1(W,A,B);
not a2(E,C);
or a3(D,W,E);
endmodule


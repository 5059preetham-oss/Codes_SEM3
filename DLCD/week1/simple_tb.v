module simple_tb;
reg A,B,C;
wire D,E;
simple s1(E,D,A,B,C);

initial begin
  #000 A=0; B=0; C=0;
  #100 A=0; B=0; C=1;
  #200 A=0; B=1; C=0;
  #300 A=1; B=0; C=0;
  #400 A=1; B=0; C=1;
  #500 A=1; B=1; C=0;
  #600 A=1; B=1; C=1; 
end

initial begin
  $monitor($time, " a=%b, b=%b, c=%b ,d=%b ,e=%b", A, B, C,D,E);
end

initial begin
  $dumpfile("simple.vcd");
  $dumpvars(0, simple_tb);
end 
endmodule
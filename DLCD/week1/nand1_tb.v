module nand1_tb;
reg a, b;
wire y;
nand1 n1(y, a, b);

initial begin
  #000 a=0; b=0;
  #100 a=0; b=1;
  #200 a=1; b=0;
  #300 a=1; b=1;
end

initial begin
  $monitor($time, " a=%b, b=%b, y=%b", a, b, y);
end

initial begin
  $dumpfile("nand1.vcd");
  $dumpvars(0, nand1_tb);
end 
endmodule
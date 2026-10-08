module xor1_tb;
reg a, b;
wire y;
xor1 x1(y, a, b);

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
  $dumpfile("xor1.vcd");
  $dumpvars(0, xor1_tb);
end 
endmodule
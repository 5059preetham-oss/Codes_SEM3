module orl_tb;
reg a, b;
wire y;
orl o1(y, a, b);

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
  $dumpfile("orl.vcd");
  $dumpvars(0, orl_tb);
end 
endmodule
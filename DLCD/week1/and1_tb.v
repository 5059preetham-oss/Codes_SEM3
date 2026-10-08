module and1_tb;
reg a, b;
wire y;
and1 a1(y, a, b);

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
  $dumpfile("and1.vcd");
  $dumpvars(0, and1_tb);
end 
endmodule
module not1_tb;
reg a;
wire y;
not1 n1(y, a);

initial begin
  #000 a=0;
  #100 a=1;
end

initial begin
  $monitor($time, " a=%b, y=%b", a, y);
end

initial begin
  $dumpfile("not1.vcd");
  $dumpvars(0, not1_tb);
end 
endmodule
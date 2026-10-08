`timescale 1ns/1ps

module two_stage_full_adder_tb;
    reg [2:0] i1;
    reg i2;
    wire Sum1;
    wire Cout1;

    integer k;

    two_stage_full_adder dut (
        .i1(i1),
        .i2(i2),
        .Sum1(Sum1),
        .Cout1(Cout1)
    );

    initial begin
        $dumpfile("two_stage_full_adder.vcd");
        $dumpvars(0, two_stage_full_adder_tb);

        i1 = 3'b000;
        i2 = 1'b0;
        #5;

        // Sweep all 16 input combinations (i2 + i1[2:0])
        for (k = 0; k < 16; k = k + 1) begin
            {i2, i1} = k[3:0];
            #10;
        end

        #10;
        $finish;
    end
endmodule

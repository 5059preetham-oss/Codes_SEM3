`timescale 1ns/1ps

module full_adder (
    input wire a,
    input wire b,
    input wire cin,
    output wire sum,
    output wire cout
);
    assign sum = a ^ b ^ cin;
    assign cout = (a & b) | (b & cin) | (a & cin);
endmodule

// Block-diagram implementation:
// FA1 takes i1[2], i1[1], i1[0]
// FA2 takes i2, FA1 sum, FA1 carry
module two_stage_full_adder (
    input wire [2:0] i1,
    input wire i2,
    output wire Sum1,
    output wire Cout1
);
    wire s0;
    wire c0;

    full_adder fa1 (
        .a(i1[2]),
        .b(i1[1]),
        .cin(i1[0]),
        .sum(s0),
        .cout(c0)
    );

    full_adder fa2 (
        .a(i2),
        .b(s0),
        .cin(c0),
        .sum(Sum1),
        .cout(Cout1)
    );
endmodule

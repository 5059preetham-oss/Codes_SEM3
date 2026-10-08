module mux2to1 (
    input wire i0,
    input wire i1,
    input wire j,
    output wire O
);

    // Using the ternary operator: if j is 1, O = i1; else O = i0
    assign O = j ? i1 : i0;

endmodule
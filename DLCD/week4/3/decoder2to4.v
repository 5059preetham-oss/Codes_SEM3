module decoder2to4 (
    input wire X,
    input wire Y,
    output wire F0,
    output wire F1,
    output wire F2,
    output wire F3
);

    // Wires for the inverted signals (NOT gates)
    wire not_X;
    wire not_Y;

    assign not_X = ~X;
    assign not_Y = ~Y;

    // AND gate logic for each minterm
    assign F0 = not_X & not_Y; // X'Y'
    assign F1 = not_X & Y;     // X'Y
    assign F2 = X & not_Y;     // XY'
    assign F3 = X & Y;         // XY

endmodule
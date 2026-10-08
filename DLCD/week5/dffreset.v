module dffreset (
    input in,
    input reset,
    input clk,
    output reg out
);
    wire df_in;

    // AND gate with inverted reset
    assign df_in = in & (~reset);

    // D Flip-Flop triggering on positive edge of CLK
    always @(posedge clk) begin
        out <= df_in;
    end
endmodule
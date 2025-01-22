#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
int main()
{
    int i;
    int n;
    pid_t childpid;
    n = 4;
    for (i = 0; i < n; ++i)
    {
        childpid = fork();
        if (childpid > 0)
            break;
    }
    wait(0);
    printf("This is process %ld with parent %ld\n", (long)getpid(), (long)getppid());
    return 0;
}

module Debouncer #(
    parameter CounterWidth = 1,       // Adjust as needed
    parameter DebounceTime = 1        // Adjust as needed
) (
    input wire DataIn,
    input wire Clk,
    input wire Reset,
    output wire DataOut
);
    reg [CounterWidth-1:0] Counter = 0;
    reg out;
    assign DataOut = out;

    always @(posedge Clk or posedge Reset) begin
        if (Reset) begin
            Counter <= 0;
            out <= 0;
        end else begin
            if (Counter == DebounceTime - 1) begin
                out = DataIn;
                Counter = 0;
            end else begin
                Counter = Counter + 1;
            end
        end
    end
endmodule
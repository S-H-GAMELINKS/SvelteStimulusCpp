<script>
    let counter = 0;

    function count() {
        counter += 1;
    }

    function reset() {
        counter = 0;
    }
</script>

<button on:click={count}>
    Clicked { counter } { counter === 1 ? 'time' : 'times' }
</button>

<button on:click={reset}>
    Reset
</button>
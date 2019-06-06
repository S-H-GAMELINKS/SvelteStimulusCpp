<!-- App.svelte -->
<script>
  import { Router, Link, Route } from "svelte-routing";
  import Home from "./routes/Home.svelte";
  import About from "./routes/About.svelte";
  import Contact from "./routes/Contact.svelte";
  import Count from "./routes/Count.svelte";

  export let url = "";
</script>

<Router url="{url}">
  <nav>
    <Link to="/">Home</Link>
    <Link to="/about">About</Link>
    <Link to="/contact">Contact</Link>
    <Link to="/count">Count</Link>
  </nav>
  <div>
    <Route path="/count" component="{Count}" />
    <Route path="/contact" component="{Contact}" />
    <Route path="/about" component="{About}" />
    <Route path="/"><Home /></Route>
  </div>
</Router>
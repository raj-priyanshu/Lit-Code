Here's the updated prompt:

---

Convert the following bullet list into a Confluence-compatible HTML tree. Output only the HTML fragment — no `<html>`, `<head>`, or `<body>` tags. Include the `<style>` block at the top.

**Style block to include exactly as-is:**

```html
<style>
  details > summary {
    list-style: none;
    cursor: pointer;
    display: inline-block;
  }
  details > summary::-webkit-details-marker { display: none; }

  .children {
    position: relative;
    margin-left: 10px;
    padding-left: 16px;
    border-left: 1.5px solid #d0d0d0;
  }

  .children > details,
  .children > .leaf {
    position: relative;
    margin: 2px 0;
  }

  .children > details::before,
  .children > .leaf::before {
    content: '';
    position: absolute;
    left: -16px;
    top: 11px;
    width: 12px;
    height: 1.5px;
    background: #d0d0d0;
  }

  .children > details:last-child::after,
  .children > .leaf:last-child::after {
    content: '';
    position: absolute;
    left: -17.5px;
    top: 12px;
    bottom: 0;
    width: 2px;
    background: #fff;
  }

  details > summary {
    font-weight: 500;
  }
  details:not([open]) > summary {
    text-decoration: underline;
    text-decoration-color: #bbb;
    text-underline-offset: 3px;
  }
  details > summary:hover { color: #555; }

  .note {
    display: block;
    font-size: 12px;
    color: #777;
    line-height: 1.4;
    margin: 0 0 2px 0;
  }

  .leaf {
    color: #444;
    padding: 1px 0;
  }
</style>
```

**Conversion rules:**

- A bullet with children → `<details><summary>label</summary><div class="children">…</div></details>`
- A bullet with no children → `<div class="leaf">label</div>`
- `^` after label → add `open` attribute to `<details>` (expanded by default)
- `| note text` after label → add `<span class="note">note text</span>` as first child inside `<details>`, before `.children`
- `#hex` at the start of a label (e.g. `#4a90d9 Backend`) → apply `style="color:#4a90d9"` to the `<summary>` or `.leaf` span
- `// tooltip text` after label → add `title="tooltip text"` on the `<summary>` or `.leaf`
- `// #hex tooltip text` → use the tooltip text for `title`, ignore the hex (native tooltips have no color)
- Nest `.children` divs to reflect indentation depth
- Do not output any `<script>` tags

**Here is the bullet list:**

```
PASTE YOUR BULLETS HERE
```

---

The syntax is identical to what you've been using so paste your existing bullets straight in.

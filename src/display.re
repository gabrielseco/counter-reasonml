open Utils;
[%bs.raw {|require('./display.css')|}];
let component = ReasonReact.statelessComponent("Display");

let text = Utils.text;

let parseIntToString = Utils.parseIntToString;

let make = (~result, _children) => {
  ...component,
  render: (_self) =>
    <div className="Display">
      <h2 className="Display__result">(parseIntToString (result))</h2>
    </div>
};

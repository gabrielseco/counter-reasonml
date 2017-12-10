open Utils;

[%bs.raw {|require('./counter.css')|}];

type state = {counter: int};

type action =
  | INCREMENT
  | DECREMENT;

let increment = (_event) => INCREMENT;

let decrement = (_event) => DECREMENT;

let component = ReasonReact.reducerComponent("Counter");

let text = Utils.text;

let make = (_children) => {
  ...component,
  reducer: (action, state) =>
    switch action {
    | INCREMENT => ReasonReact.Update({counter: state.counter + 1})
    | DECREMENT => ReasonReact.Update({counter: state.counter - 1})
    },
  initialState: () => {counter: 0},
  render: ({state, reduce}) => {
    let {counter} = state;
    <div className="Counter">
      <button className="btn" onClick=(reduce(decrement))> (text("-")) </button>
      <Display result=counter />
      <button className="btn" onClick=(reduce(increment))> (text("+")) </button>
    </div>
  }
};
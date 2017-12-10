module Utils = {
  let text = ReasonReact.stringToElement;
  let toString  = string_of_int;

  let parseIntToString = (result) => result |> toString |> text;
}
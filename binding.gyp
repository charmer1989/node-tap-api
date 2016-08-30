{
  "targets": [
    {
      "target_name": "tap",
      "sources": [
        "tap.cc",
        "wrap_trader.cpp",
        "uv_trader.cpp"
      ],
      "libraries": [
        "..\\tradeapi\\TapTradeAPI.lib"
      ],
      "include_dirs": [".\\tradeapi\\", "<!(node -e \"require('nan')\")"]
    }
  ]
}

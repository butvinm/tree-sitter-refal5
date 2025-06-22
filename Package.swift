// swift-tools-version:5.3

import Foundation
import PackageDescription

var sources = ["src/parser.c"]
if FileManager.default.fileExists(atPath: "src/scanner.c") {
    sources.append("src/scanner.c")
}

let package = Package(
    name: "TreeSitterRefal5",
    products: [
        .library(name: "TreeSitterRefal5", targets: ["TreeSitterRefal5"]),
    ],
    dependencies: [
        .package(url: "https://github.com/tree-sitter/swift-tree-sitter", from: "0.8.0"),
    ],
    targets: [
        .target(
            name: "TreeSitterRefal5",
            dependencies: [],
            path: ".",
            sources: sources,
            resources: [
                .copy("queries")
            ],
            publicHeadersPath: "bindings/swift",
            cSettings: [.headerSearchPath("src")]
        ),
        .testTarget(
            name: "TreeSitterRefal5Tests",
            dependencies: [
                "SwiftTreeSitter",
                "TreeSitterRefal5",
            ],
            path: "bindings/swift/TreeSitterRefal5Tests"
        )
    ],
    cLanguageStandard: .c11
)
